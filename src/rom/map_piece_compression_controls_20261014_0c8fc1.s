.setcpu "65816"
.segment "CODE"
.org $8FC1
map_control_0c8fc1:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
