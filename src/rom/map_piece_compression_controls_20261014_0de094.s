.setcpu "65816"
.segment "CODE"
.org $E094
map_control_0de094:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
