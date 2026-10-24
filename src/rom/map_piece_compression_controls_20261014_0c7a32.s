.setcpu "65816"
.segment "CODE"
.org $7A32
map_control_0c7a32:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
