.setcpu "65816"
.segment "CODE"
.org $5DDC
map_control_0d5ddc:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
