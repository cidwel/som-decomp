.setcpu "65816"
.segment "CODE"
.org $9881
map_control_0f9881:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
