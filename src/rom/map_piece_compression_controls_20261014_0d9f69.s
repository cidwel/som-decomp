.setcpu "65816"
.segment "CODE"
.org $9F69
map_control_0d9f69:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
