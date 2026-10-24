.setcpu "65816"
.segment "CODE"
.org $61A8
map_control_0c61a8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
