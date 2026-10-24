.setcpu "65816"
.segment "RODATA"
; UI sprite component descriptors at $C0A2BE.
ui_signed_sprite_component_descriptors_a2be:
.word $A2EE, $A3A8, $A35C, $A3F4
ui_signed_sprite_component_descriptors_a2c6:
.word $A2FB, $A3B5, $A369, $A401
ui_signed_sprite_component_descriptors_a2ce:
.word $A321, $A3CA, $A37E, $A427
ui_signed_sprite_component_descriptors_a2d6:
.word $A347, $A3DF, $A393, $A44D
ui_signed_sprite_component_descriptors_a2de:
.word $A34A, $A3E2, $A396, $A450
ui_signed_sprite_component_descriptors_a2e6:
.word $A34D, $A3E5, $A399, $A453
ui_signed_sprite_component_descriptors_a2ee:
; 2 columns x 3 rows; tile and attribute words.
.byte $32
.word $3A00, $3A01, $3A10, $3A11, $3A20, $3A21
ui_signed_sprite_component_descriptors_a2fb:
.word $A2FF, $A310
ui_signed_sprite_component_descriptors_a2ff:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A35, $7A34, $3A34, $3A35, $7A45, $7A44, $3A44, $3A45
ui_signed_sprite_component_descriptors_a310:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A37, $7A36, $3A36, $3A37, $7A47, $7A46, $3A46, $3A47
ui_signed_sprite_component_descriptors_a321:
.word $A325, $A336
ui_signed_sprite_component_descriptors_a325:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A39, $7A38, $3A38, $3A39, $7A49, $7A48, $3A48, $3A49
ui_signed_sprite_component_descriptors_a336:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A3B, $7A3A, $3A3A, $3A3B, $7A4B, $7A4A, $3A4A, $3A4B
ui_signed_sprite_component_descriptors_a347:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5B
ui_signed_sprite_component_descriptors_a34a:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5C
ui_signed_sprite_component_descriptors_a34d:
.word $A353, $A356, $A359
ui_signed_sprite_component_descriptors_a353:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A5E
ui_signed_sprite_component_descriptors_a356:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5D
ui_signed_sprite_component_descriptors_a359:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5E
ui_signed_sprite_component_descriptors_a35c:
; 2 columns x 3 rows; tile and attribute words.
.byte $32
.word $3A02, $3A03, $3A12, $3A13, $3A22, $3A23
ui_signed_sprite_component_descriptors_a369:
.word $A36D, $A36D
ui_signed_sprite_component_descriptors_a36d:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A35, $7A34, $3A36, $3A37, $7A45, $7A44, $3A46, $3A47
ui_signed_sprite_component_descriptors_a37e:
.word $A382, $A382
ui_signed_sprite_component_descriptors_a382:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A39, $7A38, $3A3A, $3A3B, $7A49, $7A48, $3A4A, $3A4B
ui_signed_sprite_component_descriptors_a393:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A6B
ui_signed_sprite_component_descriptors_a396:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A6C
ui_signed_sprite_component_descriptors_a399:
.word $A39F, $A3A2, $A3A5
ui_signed_sprite_component_descriptors_a39f:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A6D
ui_signed_sprite_component_descriptors_a3a2:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A6E
ui_signed_sprite_component_descriptors_a3a5:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A6F
ui_signed_sprite_component_descriptors_a3a8:
; 2 columns x 3 rows; tile and attribute words.
.byte $32
.word $7A03, $7A02, $7A13, $7A12, $7A23, $7A22
ui_signed_sprite_component_descriptors_a3b5:
.word $A3B9, $A3B9
ui_signed_sprite_component_descriptors_a3b9:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A37, $7A36, $3A34, $3A35, $7A47, $7A46, $3A44, $3A45
ui_signed_sprite_component_descriptors_a3ca:
.word $A3CE, $A3CE
ui_signed_sprite_component_descriptors_a3ce:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A3B, $7A3A, $3A38, $3A39, $7A4B, $7A4A, $3A48, $3A49
ui_signed_sprite_component_descriptors_a3df:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A6B
ui_signed_sprite_component_descriptors_a3e2:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A6C
ui_signed_sprite_component_descriptors_a3e5:
.word $A3EB, $A3EE, $A3F1
ui_signed_sprite_component_descriptors_a3eb:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A6D
ui_signed_sprite_component_descriptors_a3ee:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A6E
ui_signed_sprite_component_descriptors_a3f1:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A6F
ui_signed_sprite_component_descriptors_a3f4:
; 2 columns x 3 rows; tile and attribute words.
.byte $32
.word $FA21, $FA20, $FA11, $FA10, $FA01, $FA00
ui_signed_sprite_component_descriptors_a401:
.word $A405, $A416
ui_signed_sprite_component_descriptors_a405:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $FA45, $FA44, $BA44, $BA45, $FA35, $FA34, $BA34, $BA35
ui_signed_sprite_component_descriptors_a416:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $FA47, $FA46, $BA46, $BA47, $FA37, $FA36, $BA36, $BA37
ui_signed_sprite_component_descriptors_a427:
.word $A42B, $A43C
ui_signed_sprite_component_descriptors_a42b:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $FA49, $FA48, $BA48, $BA49, $FA39, $FA38, $BA38, $BA39
ui_signed_sprite_component_descriptors_a43c:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $FA4B, $FA4A, $BA4A, $BA4B, $FA3B, $FA3A, $BA3A, $BA3B
ui_signed_sprite_component_descriptors_a44d:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $FA5B
ui_signed_sprite_component_descriptors_a450:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $FA5C
ui_signed_sprite_component_descriptors_a453:
.word $A459, $A45C, $A45F
ui_signed_sprite_component_descriptors_a459:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $FA5E
ui_signed_sprite_component_descriptors_a45c:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $BA5D
ui_signed_sprite_component_descriptors_a45f:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $BA5E
