.setcpu "65816"
.segment "CODE"
.org $5E64
map_control_0d5e64:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
