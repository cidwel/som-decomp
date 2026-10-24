.setcpu "65816"
.segment "CODE"
.org $2E96
map_control_0d2e96:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
