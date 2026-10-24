.setcpu "65816"
.segment "CODE"
.org $DADB
map_control_0fdadb:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
