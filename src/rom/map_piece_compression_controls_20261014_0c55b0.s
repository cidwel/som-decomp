.setcpu "65816"
.segment "CODE"
.org $55B0
map_control_0c55b0:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
