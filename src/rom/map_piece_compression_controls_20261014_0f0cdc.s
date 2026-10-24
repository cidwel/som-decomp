.setcpu "65816"
.segment "CODE"
.org $0CDC
map_control_0f0cdc:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
