.setcpu "65816"
.segment "CODE"
.org $72FC
map_control_0f72fc:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
