.setcpu "65816"
.segment "CODE"
.org $5743
map_control_0e5743:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
