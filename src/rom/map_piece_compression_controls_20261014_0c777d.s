.setcpu "65816"
.segment "CODE"
.org $777D
map_control_0c777d:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
