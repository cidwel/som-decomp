.setcpu "65816"
.segment "RODATA"
; UI sprite component descriptors at $C0A082.
ui_ordinary_sprite_component_descriptors_a082:
.word $A0B2, $A1B0, $A146, $A21A
ui_ordinary_sprite_component_descriptors_a08a:
.word $A0C5, $A1C3, $A159, $A22D
ui_ordinary_sprite_component_descriptors_a092:
.word $A0EB, $A1D8, $A16E, $A263
ui_ordinary_sprite_component_descriptors_a09a:
.word $A121, $A1F5, $A18B, $A299
ui_ordinary_sprite_component_descriptors_a0a2:
.word $A12A, $A1FE, $A194, $A2A2
ui_ordinary_sprite_component_descriptors_a0aa:
.word $A133, $A207, $A19D, $A2AB
ui_ordinary_sprite_component_descriptors_a0b2:
; 3 columns x 3 rows; tile and attribute words.
.byte $33
.word $3A04, $3A05, $3A06, $3A14, $3A15, $3A16, $3A24, $3A25, $3A26
ui_ordinary_sprite_component_descriptors_a0c5:
.word $A0C9, $A0DA
ui_ordinary_sprite_component_descriptors_a0c9:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A31, $7A30, $3A30, $3A31, $7A41, $7A40, $3A40, $3A41
ui_ordinary_sprite_component_descriptors_a0da:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A33, $7A32, $3A32, $3A33, $7A43, $7A42, $3A42, $3A43
ui_ordinary_sprite_component_descriptors_a0eb:
.word $A0EF, $A108
ui_ordinary_sprite_component_descriptors_a0ef:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A0B, $7A0A, $3A0A, $3A0B, $7A1B, $7A1A, $3A1A, $3A1B, $7A2B, $7A2A, $3A2A, $3A2B
ui_ordinary_sprite_component_descriptors_a108:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A0D, $7A0C, $3A0C, $3A0D, $7A1D, $7A1C, $3A1C, $3A1D, $7A2D, $7A2C, $3A2C, $3A2D
ui_ordinary_sprite_component_descriptors_a121:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3C, $3A3C, $7A4C, $3A4C
ui_ordinary_sprite_component_descriptors_a12a:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3D, $3A3D, $7A4D, $3A4D
ui_ordinary_sprite_component_descriptors_a133:
.word $A139, $A13E, $A141
ui_ordinary_sprite_component_descriptors_a139:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A2E, $3A3E
ui_ordinary_sprite_component_descriptors_a13e:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5F
ui_ordinary_sprite_component_descriptors_a141:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A0E, $3A1E
ui_ordinary_sprite_component_descriptors_a146:
; 3 columns x 3 rows; tile and attribute words.
.byte $33
.word $3A07, $3A08, $3A09, $3A17, $3A18, $3A19, $3A27, $3A28, $3A29
ui_ordinary_sprite_component_descriptors_a159:
.word $A15D, $A15D
ui_ordinary_sprite_component_descriptors_a15d:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A31, $7A30, $3A32, $3A33, $7A41, $7A40, $3A42, $3A43
ui_ordinary_sprite_component_descriptors_a16e:
.word $A172, $A172
ui_ordinary_sprite_component_descriptors_a172:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A0B, $7A0A, $3A0C, $3A0D, $7A1B, $7A1A, $3A1C, $3A1D, $7A2B, $7A2A, $3A2C, $3A2D
ui_ordinary_sprite_component_descriptors_a18b:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3C, $3A3C, $7A4C, $3A4C
ui_ordinary_sprite_component_descriptors_a194:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3D, $3A3D, $7A4D, $3A4D
ui_ordinary_sprite_component_descriptors_a19d:
.word $A1A3, $A1A8, $A1AB
ui_ordinary_sprite_component_descriptors_a1a3:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A2E, $3A3E
ui_ordinary_sprite_component_descriptors_a1a8:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5F
ui_ordinary_sprite_component_descriptors_a1ab:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A0E, $3A1E
ui_ordinary_sprite_component_descriptors_a1b0:
; 3 columns x 3 rows; tile and attribute words.
.byte $33
.word $7A09, $7A08, $7A07, $7A19, $7A18, $7A17, $7A29, $7A28, $7A27
ui_ordinary_sprite_component_descriptors_a1c3:
.word $A1C7, $A1C7
ui_ordinary_sprite_component_descriptors_a1c7:
; 4 columns x 2 rows; tile and attribute words.
.byte $24
.word $7A33, $7A32, $3A30, $3A31, $7A43, $7A42, $3A40, $3A41
ui_ordinary_sprite_component_descriptors_a1d8:
.word $A1DC, $A1DC
ui_ordinary_sprite_component_descriptors_a1dc:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A0D, $7A0C, $3A0A, $3A0B, $7A1D, $7A1C, $3A1A, $3A1B, $7A2D, $7A2C, $3A2A, $3A2B
ui_ordinary_sprite_component_descriptors_a1f5:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3C, $3A3C, $7A4C, $3A4C
ui_ordinary_sprite_component_descriptors_a1fe:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3D, $3A3D, $7A4D, $3A4D
ui_ordinary_sprite_component_descriptors_a207:
.word $A20D, $A212, $A215
ui_ordinary_sprite_component_descriptors_a20d:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $7A2E, $7A3E
ui_ordinary_sprite_component_descriptors_a212:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $7A5F
ui_ordinary_sprite_component_descriptors_a215:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $7A0E, $7A1E
ui_ordinary_sprite_component_descriptors_a21a:
; 3 columns x 3 rows; tile and attribute words.
.byte $33
.word $3A50, $3A51, $3A52, $3A60, $3A61, $3A62, $3A70, $3A71, $3A72
ui_ordinary_sprite_component_descriptors_a22d:
.word $A231, $A24A
ui_ordinary_sprite_component_descriptors_a231:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A58, $7A57, $3A57, $3A58, $7A68, $7A67, $3A67, $3A68, $7A78, $7A77, $3A77, $3A78
ui_ordinary_sprite_component_descriptors_a24a:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A5A, $7A59, $3A59, $3A5A, $7A6A, $7A69, $3A69, $3A6A, $7A7A, $7A79, $3A79, $3A7A
ui_ordinary_sprite_component_descriptors_a263:
.word $A267, $A280
ui_ordinary_sprite_component_descriptors_a267:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A54, $7A53, $3A53, $3A54, $7A64, $7A63, $3A63, $3A64, $7A74, $7A73, $3A73, $3A74
ui_ordinary_sprite_component_descriptors_a280:
; 4 columns x 3 rows; tile and attribute words.
.byte $34
.word $7A56, $7A55, $3A55, $3A56, $7A66, $7A65, $3A65, $3A66, $7A76, $7A75, $3A75, $3A76
ui_ordinary_sprite_component_descriptors_a299:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3C, $3A3C, $7A4C, $3A4C
ui_ordinary_sprite_component_descriptors_a2a2:
; 2 columns x 2 rows; tile and attribute words.
.byte $22
.word $7A3D, $3A3D, $7A4D, $3A4D
ui_ordinary_sprite_component_descriptors_a2ab:
.word $A2B1, $A2B6, $A2B9
ui_ordinary_sprite_component_descriptors_a2b1:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A2F, $3A3F
ui_ordinary_sprite_component_descriptors_a2b6:
; 1 columns x 1 rows; tile and attribute words.
.byte $11
.word $3A5F
ui_ordinary_sprite_component_descriptors_a2b9:
; 1 columns x 2 rows; tile and attribute words.
.byte $21
.word $3A0E, $3A1E
