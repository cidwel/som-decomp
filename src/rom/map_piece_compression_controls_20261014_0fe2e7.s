.setcpu "65816"
.segment "CODE"
.org $E2E7
map_control_0fe2e7:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
