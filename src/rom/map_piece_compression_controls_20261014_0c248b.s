.setcpu "65816"
.segment "CODE"
.org $248B
map_control_0c248b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
