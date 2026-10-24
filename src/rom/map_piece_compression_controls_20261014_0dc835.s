.setcpu "65816"
.segment "CODE"
.org $C835
map_control_0dc835:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
