.setcpu "65816"
.segment "CODE"
.org $701D
map_control_0f701d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
