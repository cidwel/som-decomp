.setcpu "65816"
.segment "CODE"
.org $8DE9
map_control_0f8de9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
