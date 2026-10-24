.setcpu "65816"
.segment "CODE"
.org $A976
map_control_0fa976:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
