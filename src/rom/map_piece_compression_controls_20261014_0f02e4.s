.setcpu "65816"
.segment "CODE"
.org $02E4
map_control_0f02e4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
