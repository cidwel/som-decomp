.setcpu "65816"
.segment "CODE"
.org $ED9F
map_control_0ded9f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
