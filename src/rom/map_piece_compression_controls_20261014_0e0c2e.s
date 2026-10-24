.setcpu "65816"
.segment "CODE"
.org $0C2E
map_control_0e0c2e:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
