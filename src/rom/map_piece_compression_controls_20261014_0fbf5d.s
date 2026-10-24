.setcpu "65816"
.segment "CODE"
.org $BF5D
map_control_0fbf5d:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
