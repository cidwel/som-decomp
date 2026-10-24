.setcpu "65816"
.segment "CODE"
.org $73AF
map_control_0f73af:
    .byte $E5 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
