.setcpu "65816"
.segment "CODE"
.org $769A
map_control_0d769a:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
    .byte $C2 ; same-value copy count/distance
