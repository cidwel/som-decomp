.setcpu "65816"
.segment "CODE"
.org $7963
map_control_0f7963:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
