.setcpu "65816"
.segment "CODE"
.org $AABD
map_control_0daabd:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
