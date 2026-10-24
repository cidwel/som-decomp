.setcpu "65816"
.segment "CODE"
.org $D347
map_control_0fd347:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
