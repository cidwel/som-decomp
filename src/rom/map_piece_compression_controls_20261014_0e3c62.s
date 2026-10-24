.setcpu "65816"
.segment "CODE"
.org $3C62
map_control_0e3c62:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
