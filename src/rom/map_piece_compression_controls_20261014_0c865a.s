.setcpu "65816"
.segment "CODE"
.org $865A
map_control_0c865a:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
