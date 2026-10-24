.setcpu "65816"
.segment "CODE"
.org $6D4A
map_control_0e6d4a:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
