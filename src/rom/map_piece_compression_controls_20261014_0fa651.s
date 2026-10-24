.setcpu "65816"
.segment "CODE"
.org $A651
map_control_0fa651:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
