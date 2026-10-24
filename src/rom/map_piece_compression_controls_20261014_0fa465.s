.setcpu "65816"
.segment "CODE"
.org $A465
map_control_0fa465:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
