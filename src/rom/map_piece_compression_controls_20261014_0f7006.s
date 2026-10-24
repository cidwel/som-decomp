.setcpu "65816"
.segment "CODE"
.org $7006
map_control_0f7006:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
