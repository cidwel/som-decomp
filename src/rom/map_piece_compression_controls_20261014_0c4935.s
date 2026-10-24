.setcpu "65816"
.segment "CODE"
.org $4935
map_control_0c4935:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
