.setcpu "65816"
.segment "CODE"
.org $A97C
map_control_0fa97c:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
