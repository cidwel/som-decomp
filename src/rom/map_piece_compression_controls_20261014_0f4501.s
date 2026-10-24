.setcpu "65816"
.segment "CODE"
.org $4501
map_control_0f4501:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
