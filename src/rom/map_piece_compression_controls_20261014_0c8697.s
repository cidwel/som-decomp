.setcpu "65816"
.segment "CODE"
.org $8697
map_control_0c8697:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
