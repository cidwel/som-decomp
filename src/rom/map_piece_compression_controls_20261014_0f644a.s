.setcpu "65816"
.segment "CODE"
.org $644A
map_control_0f644a:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
