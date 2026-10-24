.setcpu "65816"
.segment "CODE"
.org $4930
map_control_0e4930:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
