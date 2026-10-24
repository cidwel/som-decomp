.setcpu "65816"
.segment "CODE"
.org $ED8F
map_control_0ded8f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
