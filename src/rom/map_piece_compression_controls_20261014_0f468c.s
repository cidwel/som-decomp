.setcpu "65816"
.segment "CODE"
.org $468C
map_control_0f468c:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $71 ; distance low bit/count
