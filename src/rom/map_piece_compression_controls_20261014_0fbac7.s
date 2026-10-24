.setcpu "65816"
.segment "CODE"
.org $BAC7
map_control_0fbac7:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
