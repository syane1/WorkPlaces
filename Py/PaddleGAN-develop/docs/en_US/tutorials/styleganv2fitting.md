# StyleGAN V2 Fitting Module

## StyleGAN V2 Fitting introduction

The task of StyleGAN V2 is image generation while the Fitting module inversely derives the style vector with a high degree of decoupling based on the existing image. The generated style vector can be used in tasks such as face fusion and face attribute editing.

## How to use

### Fitting

The user can use the following command to fit images：

```
cd applications/
python -u tools/styleganv2fitting.py \
       --input_image <YOUR INPUT IMAGE> \
       --need_align \
       --start_lr 0.1 \
       --final_lr 0.025 \
       --latent_level 0 1 2 3 4 5 6 7 8 9 10 11 \
       --step 100 \
       --mse_weight 1 \
       --pre_latent <PRE-PREPARED LATENT CODE PATH> \
       --output_path <DIRECTORY TO STORE OUTPUT IMAGE> \
       --weight_path <YOUR PRETRAINED MODEL PATH> \
       --model_type ffhq-config-f \
       --size 1024 \
       --style_dim 512 \
       --n_mlp 8 \
       --channel_multiplier 2 \
       --cpu
```

**params:**
- input_image: the input image file path
- need_align: whether to crop the image to an image that can be recognized by the model. For an image that has been cropped, such as the `src.png` that is pre-generated when Pixel2Style2Pixel is used to generate the style vector, the need_align parameter may not be filled in
- start_lr: learning rate at the begin of training
- final_lr: learning rate at the end of training
- latent_level: The style vector levels involved in fitting are from 0 to 17 at 1024 resolution, from 0 to 15 at 512 resolution, and so on. The lower the level, the more biased toward the overall style change. The higher the level, the more biased toward the detail style change
- step: the number of steps required to fit the image, the larger the number of steps, the longer it takes and the better the effect
- mse_weight: weight of MSE loss
- pre_latent: The pre-made style vector files are saved to facilitate better fitting. The default is empty, you can fill in the file path of `dst.npy` generated by Pixel2Style2Pixel
- output_path: the directory where the generated images are stored
- weight_path: pretrained model path
- model_type: inner model type in PaddleGAN. If you use an existing model type, `weight_path` will have no effect.
  Currently recommended use: `ffhq-config-f`
- size: model parameters, output image resolution
- style_dim: model parameters, dimensions of style z
- n_mlp: model parameters, the number of multi-layer perception layers for style z
- channel_multiplier: model parameters, channel product, affect model size and the quality of generated pictures
- cpu: whether to use cpu inference, if not, please remove it from the command

## Fitting Results

Source image:

<div align="center">
    <img src="../../imgs/pSp-input.jpg" width="300"/>
</div>

Image encoded by Pixel2Style2Pixel:

<div align="center">
    <img src="../../imgs/pSp-inversion.png" width="256"/>
</div>

After passing the style vector generated by Pixel2Style2Pixel, use the Fitting module to perform 1000 steps of fitting to get the result:

<div align="center">
    <img src="../../imgs/stylegan2fitting-sample.png" width="256"/>
</div>

## Reference

- 1. [Analyzing and Improving the Image Quality of StyleGAN](https://arxiv.org/abs/1912.04958)

  ```
  @article{Karras2019stylegan2,
    title={Analyzing and Improving the Image Quality of {StyleGAN}},
    author={Tero Karras and Samuli Laine and Miika Aittala and Janne Hellsten and Jaakko Lehtinen and Timo Aila},
    booktitle={Proc. CVPR},
    year={2020}
  }
  ```
- 2. [Encoding in Style: a StyleGAN Encoder for Image-to-Image Translation](hhttps://arxiv.org/abs/2008.00951)

  ```
  @article{richardson2020encoding,
    title={Encoding in Style: a StyleGAN Encoder for Image-to-Image Translation},
    author={Richardson, Elad and Alaluf, Yuval and Patashnik, Or and Nitzan, Yotam and Azar, Yaniv and Shapiro, Stav and Cohen-Or, Daniel},
    journal={arXiv preprint arXiv:2008.00951},
    year={2020}
  }
  ```
