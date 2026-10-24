.setcpu "65816"
.segment "CODE"
.org $DBD4
map_control_0edbd4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
