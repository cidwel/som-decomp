.setcpu "65816"
.segment "CODE"
.org $D5B5
map_control_0fd5b5:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
