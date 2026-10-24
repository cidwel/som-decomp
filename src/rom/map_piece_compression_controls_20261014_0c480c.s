.setcpu "65816"
.segment "CODE"
.org $480C
map_control_0c480c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
