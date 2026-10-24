.setcpu "65816"
.segment "CODE"
.org $96AE
map_control_0f96ae:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
