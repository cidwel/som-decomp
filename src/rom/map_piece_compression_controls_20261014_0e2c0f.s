.setcpu "65816"
.segment "CODE"
.org $2C0F
map_control_0e2c0f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
