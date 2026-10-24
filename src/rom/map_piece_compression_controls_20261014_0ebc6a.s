.setcpu "65816"
.segment "CODE"
.org $BC6A
map_control_0ebc6a:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
