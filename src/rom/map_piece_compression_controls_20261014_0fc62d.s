.setcpu "65816"
.segment "CODE"
.org $C62D
map_control_0fc62d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
