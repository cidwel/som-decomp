.setcpu "65816"
.segment "CODE"
.org $498C
map_control_0c498c:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
