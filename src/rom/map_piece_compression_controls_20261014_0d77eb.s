.setcpu "65816"
.segment "CODE"
.org $77EB
map_control_0d77eb:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $C6 ; same-value copy count/distance
