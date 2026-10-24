.setcpu "65816"
.segment "CODE"
.org $97B9
map_control_0d97b9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
